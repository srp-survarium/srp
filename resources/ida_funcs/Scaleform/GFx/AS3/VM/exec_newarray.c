void __thiscall Scaleform::GFx::AS3::VM::exec_newarray(Scaleform::GFx::AS3::VM *this, unsigned int arr_size)
{
  Scaleform::GFx::AS3::VM *v2; // esi
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // edi
  Scaleform::GFx::AS3::VM_vtbl *v4; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> a; // [esp+8h] [ebp-10h] BYREF
  int v6; // [esp+Ch] [ebp-Ch]
  Scaleform::GFx::AS3::Instances::fl::Array *v7; // [esp+10h] [ebp-8h]
  int v8; // [esp+14h] [ebp-4h]

  v2 = this;
  Scaleform::GFx::AS3::VM::MakeArray(this, &a);
  pV = a.pV;
  v2 = (Scaleform::GFx::AS3::VM *)((char *)v2 + 40);
  Scaleform::GFx::AS3::Impl::SparseArray::Pick(&a.pV->SA, (Scaleform::GFx::AS3::ValueStack *)v2, arr_size);
  v2->__vftable += 2;
  v4 = v2->__vftable;
  v6 = 0;
  a.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)12;
  v7 = pV;
  v8 = 0;
  if ( v4 )
  {
    v4->GetAdvanceStats = 0;
    v4->~Scaleform::GFx::AS3::VM = (void (__thiscall *)(Scaleform::GFx::AS3::VM *))12;
    v4[1].~Scaleform::GFx::AS3::VM = (void (__thiscall *)(Scaleform::GFx::AS3::VM *))pV;
    v4[1].GetAdvanceStats = 0;
    Scaleform::GFx::AS3::Value::AddRefInternal((Scaleform::GFx::AS3::Value *)&a);
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&a);
}
