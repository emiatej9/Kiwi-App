// Copyright 2021 Hongmin Yang

#include <clocale>
#include <codecvt>
#include <iostream>
#include <string>

#include "kiwi/Kiwi.h"
#include "kiwi/Types.h"

const std::u16string toString(const kiwi::POSTag &posTag) {
  std::u16string tagNames[] = {
      u"UNK", u"NNG",   u"NNP",     u"NNB",       u"VV",        u"VA",  u"MAG",
      u"NR",  u"NP",    u"VX",      u"MM",        u"MAJ",       u"IC",  u"XPN",
      u"XSN", u"XSV",   u"XSA",     u"XR",        u"VCP",       u"VCN", u"SF",
      u"SP",  u"SS",    u"SE",      u"SO",        u"SW",        u"SL",  u"SH",
      u"SN",  u"W_URL", u"W_EMAIL", u"W_MENTION", u"W_HASHTAG", u"JKS", u"JKC",
      u"JKG", u"JKO",   u"JKB",     u"JKV",       u"JKQ",       u"JX",  u"JC",
      u"EP",  u"EF",    u"EC",      u"ETN",       u"ETM",       u"V",   u"MAX"};

  return tagNames[static_cast<uint8_t>(posTag)];
}

const std::wstring convert(const std::u16string str,
                           const kiwi::TokenResult &tokenResult) {
  std::u16string result;
  result.reserve(str.size() * 3);

  auto begin = tokenResult.first.begin();
  auto end = tokenResult.first.end();
  for (auto iter = begin; iter != end; ++iter) {
    result += iter->str;
    result += '/';
    result += toString(iter->tag);

    if (iter != end) {
      result += u" + ";
    }
  }

  return {std::begin(result), std::end(result)};
}

int main() {
  const std::string model_path = "./model";
  const std::u16string sentence = u"이것은 먹이다.";

  kiwi::KiwiBuilder kiwiBuilder =
     kiwi::KiwiBuilder{model_path, 0, kiwi::BuildOption::none};

  kiwi::Kiwi kiwi = kiwiBuilder.build();
  kiwi::TokenResult tokenResult = kiwi.analyze(sentence, kiwi::Match::all);

  std::wcout.imbue(std::locale("ko_KR.UTF-8"));
  std::wcout << convert(sentence, tokenResult) << std::endl;

  return 0;
}
