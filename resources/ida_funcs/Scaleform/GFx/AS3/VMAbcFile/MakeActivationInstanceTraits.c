Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> *__thiscall Scaleform::GFx::AS3::VMAbcFile::MakeActivationInstanceTraits(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> *result,
        const Scaleform::GFx::AS3::Abc::MbiInd mbi_ind)
{
  const Scaleform::GFx::AS3::Abc::MethodBodyInfo *v4; // ebx
  Scaleform::GFx::AS3::VM *VMRef; // edi
  Scaleform::GFx::AS3::InstanceTraits::Activation *v6; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v7; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> *v8; // eax

  v4 = this->File.pObject->MethodBodies.Info.Data.Data[mbi_ind.Ind];
  VMRef = this->VMRef;
  v6 = (Scaleform::GFx::AS3::InstanceTraits::Activation *)VMRef->MHeap->Alloc(VMRef->MHeap, 108u, 0);
  if ( v6 )
  {
    Scaleform::GFx::AS3::InstanceTraits::Activation::Activation(v6, this, (Scaleform::GFx::ASStringNode *)VMRef, v4);
    result->pV = v7;
    return result;
  }
  else
  {
    v8 = result;
    result->pV = 0;
  }
  return v8;
}
