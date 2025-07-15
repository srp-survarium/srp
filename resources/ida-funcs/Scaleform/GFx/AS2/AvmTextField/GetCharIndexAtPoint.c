void __cdecl Scaleform::GFx::AS2::AvmTextField::GetCharIndexAtPoint(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v3; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  int CharIndexAtPoint; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  int v8; // edi
  long double v9; // st7
  Scaleform::GFx::AS2::Environment *Env; // [esp+4h] [ebp-14h]
  Scaleform::GFx::AS2::Environment *v11; // [esp+4h] [ebp-14h]
  float v12; // [esp+4h] [ebp-14h]
  long double v13; // [esp+10h] [ebp-8h]
  float v14; // [esp+1Ch] [ebp+4h]
  float v15; // [esp+1Ch] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = fn->ThisPtr;
    v3 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 ? 0 : ThisPtr[1].__vftable;
    if ( fn->NArgs >= 2 )
    {
      Env = fn->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v13 = Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
      v11 = fn->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      v14 = Scaleform::GFx::AS2::Value::ToNumber(v5, v11) * 20.0;
      v12 = v14;
      v15 = 20.0 * v13;
      CharIndexAtPoint = Scaleform::Render::Text::DocView::GetCharIndexAtPoint(
                           (Scaleform::Render::Text::DocView *)v3[1].GetMemberRaw,
                           v15,
                           v12);
      Result = fn->Result;
      v8 = CharIndexAtPoint;
      if ( CharIndexAtPoint == -1 )
      {
        if ( Result->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(Result);
        v9 = -1.0;
        Result->T.Type = 3;
      }
      else
      {
        if ( Result->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(Result);
        v9 = (double)v8;
        Result->T.Type = 3;
        if ( v8 < 0 )
        {
          Result->NV.NumberValue = v9 + 4294967296.0;
          return;
        }
      }
      Result->NV.NumberValue = v9;
    }
  }
}
