void __thiscall Scaleform::Render::RectPacker::AddRect(
        Scaleform::Render::RectPacker *this,
        unsigned int w,
        unsigned int h,
        unsigned int id)
{
  Scaleform::ArrayPagedLH_POD<unsigned int,6,64,2> *p_Failed; // esi
  unsigned int v5; // edi
  Scaleform::Render::RectPacker::RectType val; // [esp+0h] [ebp-Ch] BYREF

  if ( w && h && w <= this->Width && h <= this->Height )
  {
    val.x = w;
    val.y = h;
    val.Id = id;
    Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::RectType,8,64,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::RectType,2>>::PushBack(
      &this->SrcRects,
      &val);
  }
  else
  {
    p_Failed = &this->Failed;
    v5 = this->Failed.Size >> 6;
    if ( v5 >= this->Failed.NumPages )
      Scaleform::ArrayPagedBase<unsigned int,6,64,Scaleform::AllocatorPagedLH_POD<unsigned int,2>>::allocatePage(
        &this->Failed,
        this->Failed.Size >> 6);
    p_Failed->Pages[v5][p_Failed->Size++ & 0x3F] = id;
  }
}
