void __thiscall Scaleform::GFx::AS2::MatrixObject::MatrixObject(
        Scaleform::GFx::AS2::MatrixObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::Render::Matrix2x4<float> m; // [esp+10h] [ebp-20h] BYREF

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::MatrixObject_vtbl *)&Scaleform::GFx::AS2::Object::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::MatrixObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Matrix);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
  m.M[0][0] = 1.0;
  m.M[0][1] = 0.0;
  m.M[0][2] = 0.0;
  m.M[0][3] = 0.0;
  m.M[1][0] = 0.0;
  m.M[1][2] = 0.0;
  m.M[1][3] = 0.0;
  m.M[1][1] = 1.0;
  Scaleform::GFx::AS2::MatrixObject::SetMatrix(this, penv, &m);
}
