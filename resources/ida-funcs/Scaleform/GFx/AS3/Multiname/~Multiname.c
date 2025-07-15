void __thiscall Scaleform::GFx::AS3::Multiname::~Multiname(Scaleform::GFx::AS3::Multiname *this)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *p_Name; // ecx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // ecx
  unsigned int RefCount; // eax

  Flags = this->Name.Flags;
  p_Name = &this->Name;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_Name);
  }
  pObject = this->Obj.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
}
