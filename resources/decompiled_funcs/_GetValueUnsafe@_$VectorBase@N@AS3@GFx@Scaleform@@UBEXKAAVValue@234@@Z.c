void __thiscall Scaleform::GFx::AS3::VectorBase<double>::GetValueUnsafe(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  long double v3; // [esp+0h] [ebp-8h]

  v3 = this->ValueA.Data.Data[ind];
  v->Flags = v->Flags & 0xFFFFFFE0 | 4;
  v->value.VNumber = v3;
}
