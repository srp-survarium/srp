Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VM::constructBuiltinObject(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *pobj,
        const char *gname,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  __int16 Flags; // dx
  Scaleform::GFx::AS3::Object *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::ASStringNode *CurrentDomain; // [esp-14h] [ebp-28h]
  Scaleform::GFx::AS3::Value v; // [esp+4h] [ebp-10h] BYREF

  CurrentDomain = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  v.Flags = 0;
  v.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::VM::Construct(this, gname, CurrentDomain, &v, argc, argv, 1);
  Flags = v.Flags;
  if ( !this->HandleException && (v.Flags & 0x1F) != 0 && ((v.Flags & 0x1F) - 12 > 3 || v.value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)pobj,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v.value.VS._1.VInt);
    result->Result = 1;
    Scaleform::GFx::AS3::Value::~Value(&v);
    return result;
  }
  pObject = pobj->pObject;
  if ( pobj->pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      pobj->pObject = (Scaleform::GFx::AS3::Object *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        Flags = v.Flags;
      }
    }
    pobj->pObject = 0;
  }
  if ( this->HandleException )
    this->HandleException = 0;
  result->Result = 0;
  if ( (Flags & 0x1Fu) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      pWeakProxy = v.Bonus.pWeakProxy;
      --v.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        return result;
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
  return result;
}
