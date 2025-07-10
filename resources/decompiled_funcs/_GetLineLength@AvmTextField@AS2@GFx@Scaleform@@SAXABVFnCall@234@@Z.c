void __cdecl Scaleform::GFx::AS2::AvmTextField::GetLineLength(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v2; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  signed int v4; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  signed int LineLength; // eax
  long double val; // st7
  Scaleform::GFx::AS2::Environment *val_4; // [esp+4h] [ebp-Ch]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = fn->ThisPtr;
    v2 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 ? 0 : ThisPtr[1].__vftable;
    if ( fn->NArgs >= 1 )
    {
      val_4 = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v4 = (int)Scaleform::GFx::AS2::Value::ToNumber(v3, val_4);
      if ( v4 >= 0 )
      {
        LineLength = Scaleform::Render::Text::DocView::GetLineLength(
                       (Scaleform::Render::Text::DocView *)v2[1].GetMemberRaw,
                       v4,
                       0);
        if ( LineLength == -1 )
        {
          val = -1.0;
        }
        else
        {
          val = (double)LineLength;
          if ( LineLength < 0 )
          {
            Scaleform::GFx::AS2::Value::SetNumber(fn->Result, val + 4294967296.0);
            return;
          }
        }
        Scaleform::GFx::AS2::Value::SetNumber(fn->Result, val);
      }
      else
      {
        Result = fn->Result;
        if ( Result->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->NV.NumberValue = -1.0;
        Result->T.Type = 3;
      }
    }
  }
}
