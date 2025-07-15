Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> *__thiscall Scaleform::GFx::AS3::VMAbcFile::MakeActivationInstanceTraits(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> *result,
        const Scaleform::GFx::AS3::Abc::MbiInd mbi_ind,
        const Scaleform::GFx::ASString *name)
{
  const Scaleform::GFx::AS3::Abc::MethodBodyInfo *v5; // ebx
  Scaleform::GFx::AS3::VM *VMRef; // edi
  Scaleform::GFx::AS3::InstanceTraits::Activation *v7; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v8; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> *v9; // eax

  v5 = this->File.pObject->MethodBodies.Info.Data.Data[mbi_ind.Ind];
  VMRef = this->VMRef;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::Activation *)VMRef->MHeap->Alloc(VMRef->MHeap, 108u, 0);
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::Activation::Activation(v7, this, VMRef, v5, name);
    result->pV = v8;
    return result;
  }
  else
  {
    v9 = result;
    result->pV = 0;
  }
  return v9;
}
