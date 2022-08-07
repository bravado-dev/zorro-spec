#ifndef ZORRO_HPP
#define ZORRO_HPP
#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <bit>
#include <chrono>

namespace zorro {
using Hash = char8_t[64];
struct TreeEntry {
  std::string name;
  std::int64_t size;
  std::uint32_t mode;
  std::byte hash[32];
  std::vector<std::byte> blob; // inline small blob (< 2048 byte)
};

struct Tree {
  Hash hash;
  std::vector<TreeEntry> entries;
};

struct Signature {
  std::string name;
  std::string email;
  std::chrono::system_clock::time_point when;
};

struct Commit {
  Hash hash;
  std::vector<Hash> parents;
  Hash tree_hash;
  std::string message;
  Signature author;
  Signature committer;
};

struct Branch {
  Hash hash;
  std::string name;
};

class Hasher {
public:
  void Update(const std::byte *b, size_t len);
};

class Repository {};

} // namespace zorro

#endif