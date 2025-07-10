Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch> *__thiscall Scaleform::GFx::AS3::Classes::fl::Catch::MakeInstanceTraits(
        Scaleform::GFx::AS3::Classes::fl::Catch *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch> *result,
        Scaleform::GFx::AS3::VMAbcFile *file,
        const Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *e)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Catch *v5; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::Catch *v6; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch> *v7; // eax
  int v8; // [esp+4h] [ebp-4h] BYREF

  v8 = 328;
  v5 = (Scaleform::GFx::AS3::InstanceTraits::fl::Catch *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           this,
                                                           120,
                                                           &v8);
  if ( v5 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Catch::Catch(v5, file, this->pTraits.pObject->pVM, e);
    result->pObject = v6;
    return result;
  }
  else
  {
    v7 = result;
    result->pObject = 0;
  }
  return v7;
}
