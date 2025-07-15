void __thiscall Scaleform::GFx::AS3::SlotInfo::DestroyPrimitiveMember(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::Object *obj)
{
  int v2; // ecx
  Scaleform::GFx::AS3::Value *v3; // eax
  int v4; // ecx
  int v5; // ecx
  Scaleform::GFx::ASStringNode *Flags; // eax
  unsigned int v8; // edx
  int v9; // eax

  v2 = *(_DWORD *)this;
  v3 = (Scaleform::GFx::AS3::Value *)((char *)obj + ((32 * v2) >> 15));
  v4 = (v2 << 22 >> 27) - 2;
  if ( v4 )
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      if ( v5 == 6 )
      {
        Flags = (Scaleform::GFx::ASStringNode *)v3->Flags;
        if ( Flags )
        {
          if ( Flags->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(Flags);
        }
      }
    }
    else
    {
      v8 = v3->Flags;
      if ( v3->Flags )
      {
        if ( (v8 & 1) != 0 )
        {
          v3->Flags = v8 - 1;
        }
        else
        {
          v9 = *(_DWORD *)((v8 & 0xFFFFFFF9) + 0x10);
          if ( (v9 & 0x3FFFFF) != 0 )
          {
            *(_DWORD *)((v8 & 0xFFFFFFF9) + 0x10) = v9 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v8 & 0xFFFFFFF9));
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::Destruct<Scaleform::GFx::AS3::Value>(v3);
  }
}
