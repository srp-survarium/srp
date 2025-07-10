void __cdecl Scaleform::GFx::AS2::RectangleProto::SetEmpty(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // ecx
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::Render::Rect<double> r; // [esp+4h] [ebp-20h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Rectangle )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    Env = fn->Env;
    r.x1 = 0.0;
    r.y1 = 0.0;
    r.x2 = 0.0;
    r.y2 = 0.0;
    Scaleform::GFx::AS2::RectangleObject::SetProperties(p_pProto, Env, &r);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}
