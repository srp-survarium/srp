Scaleform::GFx::AS2::FunctionRef *__thiscall Scaleform::GFx::AS2::FunctionObject::ToFunction(
        Scaleform::GFx::AS2::FunctionObject *this,
        Scaleform::GFx::AS2::FunctionRef *result)
{
  Scaleform::GFx::AS2::FunctionRef *v2; // eax
  Scaleform::GFx::AS2::FunctionObject *v3; // ecx

  v2 = result;
  v3 = (Scaleform::GFx::AS2::FunctionObject *)((char *)this - 16);
  result->Flags = 0;
  result->Function = v3;
  result->pLocalFrame = 0;
  if ( v3 )
    v3->RefCount = (v3->RefCount + 1) & 0x8FFFFFFF;
  return v2;
}
