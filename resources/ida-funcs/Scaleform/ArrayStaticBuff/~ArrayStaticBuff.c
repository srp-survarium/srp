void __thiscall Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::~ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>(
        Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *this)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> **p_Data; // esi
  int i; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v4; // ecx
  unsigned int RefCount; // eax

  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::Clear(this);
  p_Data = &this->Data;
  for ( i = 31; i >= 0; --i )
  {
    v4 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*--p_Data;
    if ( v4 )
    {
      if ( ((unsigned __int8)v4 & 1) != 0 )
      {
        *p_Data = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)((char *)&v4[-1].RefCount + 3);
      }
      else
      {
        RefCount = v4->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v4->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
        }
      }
    }
  }
}
