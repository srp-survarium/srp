void __thiscall Scaleform::GFx::AS2::RectangleObject::GetProperties(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Value *params)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // esi

  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, "x", params);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, psc, "y", params + 1);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, psc, "width", params + 2);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, psc, "height", params + 3);
}


void __thiscall Scaleform::GFx::AS2::RectangleObject::GetProperties(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::Render::Rect<double> *r)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // ebx
  long double v4; // st7
  Scaleform::GFx::AS2::Value *v5; // esi
  int v6; // edi
  long double v7; // [esp+Ch] [ebp-58h]
  long double v8; // [esp+14h] [ebp-50h]
  long double v9; // [esp+1Ch] [ebp-48h]
  Scaleform::GFx::AS2::Value params[4]; // [esp+24h] [ebp-40h] BYREF
  _UNKNOWN *retaddr; // [esp+64h] [ebp+0h] BYREF

  params[0].T.Type = 0;
  params[1].T.Type = 0;
  params[2].T.Type = 0;
  params[3].T.Type = 0;
  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    "x",
    params);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, &penv->StringContext, "y", &params[1]);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, &penv->StringContext, "width", &params[2]);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, &penv->StringContext, "height", &params[3]);
  v8 = Scaleform::GFx::AS2::Value::ToNumber(&params[2], penv);
  v9 = Scaleform::GFx::AS2::Value::ToNumber(&params[3], penv);
  v7 = Scaleform::GFx::AS2::Value::ToNumber(params, penv);
  v4 = Scaleform::GFx::AS2::Value::ToNumber(&params[1], penv);
  r->x1 = v7;
  v5 = (Scaleform::GFx::AS2::Value *)&retaddr;
  v6 = 3;
  r->y1 = v4;
  r->x2 = v7 + v8;
  r->y2 = v4 + v9;
  do
  {
    --v5;
    if ( v5->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v5);
    --v6;
  }
  while ( v6 >= 0 );
}
