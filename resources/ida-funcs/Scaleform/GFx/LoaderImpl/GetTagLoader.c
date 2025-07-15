bool __cdecl Scaleform::GFx::LoaderImpl::GetTagLoader(
        unsigned int tagType,
        void (__stdcall **plf)(Scaleform::GFx::LoadProcess *, const Scaleform::GFx::TagInfo *))
{
  void (__stdcall *v2)(Scaleform::GFx::LoadProcess *, const Scaleform::GFx::TagInfo *); // ecx
  void (__stdcall *v4)(Scaleform::GFx::LoadProcess *, const Scaleform::GFx::TagInfo *); // ecx

  if ( tagType >= 0x5C )
  {
    if ( tagType - 1000 > 9 )
    {
      *plf = 0;
      return *plf != 0;
    }
    else
    {
      v4 = (void (__stdcall *)(Scaleform::GFx::LoadProcess *, const Scaleform::GFx::TagInfo *))*(&ssl3_ciphers[61].strength_bits
                                                                                               + tagType);
      *plf = v4;
      return v4 != 0;
    }
  }
  else
  {
    v2 = Scaleform::GFx::SWF_TagLoaderTable[tagType];
    *plf = v2;
    return v2 != 0;
  }
}
