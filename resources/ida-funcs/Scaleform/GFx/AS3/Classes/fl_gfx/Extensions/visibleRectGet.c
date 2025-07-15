void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::visibleRectGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle> *result)
{
  void (__thiscall *v3)(Scaleform::GFx::AS3::VM *); // ecx
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Value *v5; // esi
  int i; // edi
  unsigned int Flags; // eax
  float v8; // [esp+FCh] [ebp-64h]
  float v9; // [esp+FCh] [ebp-64h]
  Scaleform::GFx::AS3::Value v10; // [esp+100h] [ebp-60h] BYREF
  float v11; // [esp+110h] [ebp-50h] BYREF
  float v12; // [esp+114h] [ebp-4Ch]
  float v13; // [esp+118h] [ebp-48h]
  float v14; // [esp+11Ch] [ebp-44h]
  _DWORD v15[2]; // [esp+120h] [ebp-40h] BYREF
  double v16; // [esp+128h] [ebp-38h]
  int v17; // [esp+130h] [ebp-30h]
  int v18; // [esp+134h] [ebp-2Ch]
  double v19; // [esp+138h] [ebp-28h]
  int v20; // [esp+140h] [ebp-20h]
  int v21; // [esp+144h] [ebp-1Ch]
  double v22; // [esp+148h] [ebp-18h]
  int v23; // [esp+150h] [ebp-10h]
  int v24; // [esp+154h] [ebp-Ch]
  double v25; // [esp+158h] [ebp-8h]
  char vars0; // [esp+160h] [ebp+0h] BYREF

  v3 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  (*(void (__thiscall **)(void (__thiscall *)(Scaleform::GFx::AS3::VM *), float *))(*(_DWORD *)v3 + 68))(v3, &v11);
  v16 = v11;
  pObject = this->pTraits.pObject;
  v19 = v12;
  v15[0] = 4;
  v15[1] = 0;
  v17 = 4;
  v18 = 0;
  v8 = v13 - v11;
  v20 = 4;
  v21 = 0;
  v22 = v8;
  v23 = 4;
  v24 = 0;
  v10.Flags = 0;
  v10.Bonus.pWeakProxy = 0;
  v9 = v14 - v12;
  v25 = v9;
  (*(void (__thiscall **)(unsigned int, Scaleform::GFx::AS3::Value *, int, _DWORD *, int))(*(_DWORD *)pObject->pVM[1].ScopeStack.Data.Size
                                                                                         + 48))(
    pObject->pVM[1].ScopeStack.Data.Size,
    &v10,
    4,
    v15,
    1);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v10.value.VS._1.VInt);
  if ( (v10.Flags & 0x1F) > 9 )
  {
    if ( (v10.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  v5 = (Scaleform::GFx::AS3::Value *)&vars0;
  for ( i = 3; i >= 0; --i )
  {
    Flags = v5[-1].Flags;
    --v5;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v5);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v5);
    }
  }
}
