void __cdecl Scaleform::GFx::AS2::AvmTextField::GetFirstCharInParagraph(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v2; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  long double v4; // st7
  Scaleform::GFx::AS2::Value *Result; // esi
  int FirstCharInParagraph; // eax
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
      v4 = Scaleform::GFx::AS2::Value::ToNumber(v3, val_4);
      if ( (int)v4 >= 0 )
      {
        FirstCharInParagraph = Scaleform::Render::Text::DocView::GetFirstCharInParagraph(
                                 (Scaleform::Render::Text::DocView *)v2[1].GetMemberRaw,
                                 (int)v4);
        if ( FirstCharInParagraph == -1 )
        {
          val = -1.0;
        }
        else
        {
          val = (double)FirstCharInParagraph;
          if ( FirstCharInParagraph < 0 )
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
