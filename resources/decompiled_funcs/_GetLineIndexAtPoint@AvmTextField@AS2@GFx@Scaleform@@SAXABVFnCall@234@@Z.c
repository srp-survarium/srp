void __cdecl Scaleform::GFx::AS2::AvmTextField::GetLineIndexAtPoint(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v3; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  unsigned int LineIndexAtPoint; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  int v8; // edi
  long double v9; // st7
  Scaleform::GFx::AS2::Environment *y; // [esp+4h] [ebp-14h]
  Scaleform::GFx::AS2::Environment *ya; // [esp+4h] [ebp-14h]
  float yb; // [esp+4h] [ebp-14h]
  long double x; // [esp+10h] [ebp-8h]
  float fna; // [esp+1Ch] [ebp+4h]
  float fnb; // [esp+1Ch] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = fn->ThisPtr;
    v3 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 ? 0 : ThisPtr[1].__vftable;
    if ( fn->NArgs >= 2 )
    {
      y = fn->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      x = Scaleform::GFx::AS2::Value::ToNumber(v4, y);
      ya = fn->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      fna = Scaleform::GFx::AS2::Value::ToNumber(v5, ya) * 20.0;
      yb = fna;
      fnb = 20.0 * x;
      LineIndexAtPoint = Scaleform::Render::Text::DocView::GetLineIndexAtPoint(
                           (Scaleform::Render::Text::DocView *)v3[1].GetMemberRaw,
                           fnb,
                           yb);
      Result = fn->Result;
      v8 = LineIndexAtPoint;
      if ( LineIndexAtPoint == -1 )
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
