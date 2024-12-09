#include "Winplus_defines.hpp"
#include "Winplus_types.hpp"

namespace winplus::compiler::fs {
enum CacheType { ERROR, APP_ID };

struct Cache {
  CacheType type;
  winplus::string title;
  winplus::u32 id;
  winplus::u16 enumId;
};

WINPLUS_API bool IsCacheFolderCreated();
WINPLUS_API void InitCachePath();
WINPLUS_API void AddCache(CacheType type, winplus::string title);
WINPLUS_API void RemoveCache(winplus::string title);
} // namespace winplus::compiler::fs