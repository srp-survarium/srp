void __thiscall Scaleform::GFx::AS2::ArrayObject::SetElementSafe(
        Scaleform::GFx::AS2::ArrayObject *this,
        int idx,
        const Scaleform::GFx::AS2::Value *val)
{
  int v3; // edi
  bool v5; // sf
  bool v6; // of
  Scaleform::GFx::AS2::Value *v7; // eax

  v3 = idx;
  v6 = __OFSUB__(idx, this->Elements.Data.Size);
  v5 = (signed int)(idx - this->Elements.Data.Size) < 0;
  this->LengthValueOverriden = 0;
  if ( v5 == v6 )
    Scaleform::GFx::AS2::ArrayObject::Resize(this, v3 + 1);
  if ( !this->Elements.Data.Data[v3] )
  {
    idx = 323;
    v7 = (Scaleform::GFx::AS2::Value *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         16,
                                         &idx);
    if ( v7 )
      v7->T.Type = 0;
    else
      v7 = 0;
    this->Elements.Data.Data[v3] = v7;
  }
  Scaleform::GFx::AS2::Value::operator=(this->Elements.Data.Data[v3], val);
}
