char __cdecl Scaleform::GFx::RegisterTagLoader(
        unsigned int tagType,
        void (__stdcall *tagLoaderFunc)(Scaleform::GFx::LoadProcess *, const Scaleform::GFx::TagInfo *))
{
  if ( tagType >= 0x5C )
    return 0;
  Scaleform::GFx::SWF_TagLoaderTable[tagType] = tagLoaderFunc;
  return 1;
}
