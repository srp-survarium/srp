void __thiscall Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat>,long>::~UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat>,long>(
        Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>,Scaleform::GFx::AS3::Value const &> *this)
{
  Scaleform::GFx::AS3::Value *Result; // ecx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *pObject; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v5; // ecx
  unsigned int v6; // eax

  if ( !this->Vm->HandleException )
  {
    Result = this->Result;
    pObject = this->r.pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::Value::AssignUnsafe(Result, pObject);
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) == 0 )
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
  }
  v5 = this->r.pObject;
  if ( v5 )
  {
    if ( ((unsigned __int8)v5 & 1) != 0 )
    {
      this->r.pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)((char *)v5 - 1);
    }
    else
    {
      v6 = v5->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v6) != 0 )
      {
        v5->RefCount = v6 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
      }
    }
  }
}
