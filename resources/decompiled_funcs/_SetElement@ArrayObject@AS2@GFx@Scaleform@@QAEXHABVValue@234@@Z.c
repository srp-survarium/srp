void __thiscall Scaleform::GFx::AS2::ArrayObject::SetElement(
        Scaleform::GFx::AS2::ArrayObject *this,
        int i,
        const Scaleform::GFx::AS2::Value *val)
{
  int v3; // edi
  Scaleform::GFx::AS2::Value **Data; // eax
  Scaleform::GFx::AS2::Value *v6; // eax

  v3 = i;
  if ( i >= 0 && i < (signed int)this->Elements.Data.Size )
  {
    Data = this->Elements.Data.Data;
    this->LengthValueOverriden = 0;
    if ( !Data[v3] )
    {
      i = 323;
      v6 = (Scaleform::GFx::AS2::Value *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           16,
                                           &i);
      if ( v6 )
        v6->T.Type = 0;
      else
        v6 = 0;
      this->Elements.Data.Data[v3] = v6;
    }
    Scaleform::GFx::AS2::Value::operator=(this->Elements.Data.Data[v3], val);
  }
}
