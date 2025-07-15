void __thiscall Scaleform::GFx::AS3::ASSharedObjectLoader::PopObject(Scaleform::GFx::AS3::ASSharedObjectLoader *this)
{
  unsigned int Size; // eax
  Scaleform::Array<Scaleform::GFx::AS3::Instances::fl::Object *,2,Scaleform::ArrayDefaultPolicy> *p_ObjectStack; // esi
  unsigned int v4; // edi
  Scaleform::GFx::AS3::Traits *pObject; // eax

  Size = this->ObjectStack.Data.Size;
  p_ObjectStack = &this->ObjectStack;
  v4 = Size - 1;
  if ( Size )
  {
    if ( v4 < this->ObjectStack.Data.Policy.Capacity >> 1 )
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &p_ObjectStack->Data,
        p_ObjectStack,
        v4);
  }
  else if ( v4 >= this->ObjectStack.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &p_ObjectStack->Data,
      p_ObjectStack,
      v4 + (v4 >> 2));
  }
  p_ObjectStack->Data.Size = v4;
  pObject = p_ObjectStack->Data.Data[v4 - 1]->pTraits.pObject;
  this->bArrayIsTop = pObject->TraitsType == Traits_Array && (pObject->Flags & 0x20) == 0;
}
