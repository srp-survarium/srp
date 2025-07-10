void __thiscall Scaleform::GFx::AS2::Value::Value(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        void (__cdecl *func)(const Scaleform::GFx::AS2::FnCall *))
{
  Scaleform::GFx::AS2::Object *v4; // eax
  int v5; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax

  this->T.Type = 8;
  v4 = (Scaleform::GFx::AS2::Object *)psc->pContext->pHeap->Alloc(psc->pContext->pHeap, 56, 0);
  v5 = (int)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, psc);
    *(_DWORD *)v5 = &Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_DWORD *)(v5 + 16) = &Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_DWORD *)(v5 + 52) = func;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
    Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)(v5 + 16), psc, Prototype);
  }
  else
  {
    v5 = 0;
  }
  this->NV.Int32Value = v5;
  this->V.FunctionValue.Flags = 0;
  this->V.FunctionValue.pLocalFrame = 0;
}
