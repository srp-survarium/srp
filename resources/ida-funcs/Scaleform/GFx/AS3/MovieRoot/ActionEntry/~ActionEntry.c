void __thiscall Scaleform::GFx::AS3::MovieRoot::ActionEntry::~ActionEntry(
        Scaleform::GFx::AS3::MovieRoot::ActionEntry *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v6; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::DisplayObject *v8; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pNLoadInitCL.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Flags = this->Function.Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Function.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      this->Function.Flags &= 0xFFFFFDE0;
      this->Function.Bonus.pWeakProxy = 0;
      this->Function.value.VS._1.VInt = 0;
      this->Function.value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->Function);
    }
  }
  v6 = this->pAS3Obj.pObject;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      this->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v6 - 1);
    }
    else
    {
      RefCount = v6->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v6->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
      }
    }
  }
  v8 = this->pCharacter.pObject;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
}
