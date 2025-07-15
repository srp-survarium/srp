void __cdecl Scaleform::GFx::AS2::AvmTextField::SetTextFormat(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::TextField *v2; // edi
  int NArgs; // eax
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Object *v5; // eax
  Scaleform::GFx::AS2::Object *v6; // esi
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::AS2::Object *v9; // ebx
  Scaleform::GFx::AS2::Value *v10; // eax
  long double v11; // st7
  unsigned int v12; // esi
  Scaleform::GFx::AS2::Value *v13; // eax
  Scaleform::GFx::AS2::Object *v14; // eax
  Scaleform::GFx::AS2::Object *v15; // ebx
  Scaleform::GFx::AS2::Value *v16; // eax
  long double v17; // st7
  Scaleform::GFx::AS2::Value *v18; // eax
  double v19; // st7
  unsigned int v20; // ebp
  Scaleform::GFx::AS2::Environment *v21; // [esp-10h] [ebp-1Ch]
  Scaleform::GFx::AS2::Environment *v22; // [esp-10h] [ebp-1Ch]
  Scaleform::GFx::AS2::Environment *v23; // [esp-10h] [ebp-1Ch]
  Scaleform::GFx::AS2::Environment *v24; // [esp-10h] [ebp-1Ch]
  Scaleform::GFx::AS2::Environment *v25; // [esp-10h] [ebp-1Ch]
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-14h]
  double startPos; // [esp+4h] [ebp-8h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = fn->ThisPtr;
    v2 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 ? 0 : (Scaleform::GFx::TextField *)ThisPtr[1].__vftable;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v2) )
    {
      NArgs = fn->NArgs;
      if ( NArgs == 1 )
      {
        Env = fn->Env;
        v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v5 = Scaleform::GFx::AS2::Value::ToObject(v4, Env);
        v6 = v5;
        if ( v5 )
        {
          if ( v5->GetObjectType(&v5->Scaleform::GFx::AS2::ObjectInterface) == Object_TextFormat )
          {
            Scaleform::Render::Text::DocView::SetTextFormat(
              v2->pDocument.pObject,
              (const Scaleform::Render::Text::TextFormat *)&v6[1],
              0,
              0xFFFFFFFF);
            Scaleform::Render::Text::DocView::SetParagraphFormat(
              v2->pDocument.pObject,
              (const Scaleform::Render::Text::ParagraphFormat *)&v6[1].ResolveHandler.Flags,
              0,
              0xFFFFFFFF);
            Scaleform::GFx::TextField::SetDirtyFlag(v2);
          }
        }
      }
      else if ( NArgs == 2 )
      {
        v21 = fn->Env;
        v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v8 = Scaleform::GFx::AS2::Value::ToObject(v7, v21);
        v9 = v8;
        if ( v8 )
        {
          if ( v8->GetObjectType(&v8->Scaleform::GFx::AS2::ObjectInterface) == Object_TextFormat )
          {
            v22 = fn->Env;
            v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
            v11 = Scaleform::GFx::AS2::Value::ToNumber(v10, v22);
            if ( v11 >= 0.0 )
            {
              v12 = (__int64)v11;
              Scaleform::Render::Text::DocView::SetTextFormat(
                v2->pDocument.pObject,
                (const Scaleform::Render::Text::TextFormat *)&v9[1],
                v12,
                v12 + 1);
              Scaleform::Render::Text::DocView::SetParagraphFormat(
                v2->pDocument.pObject,
                (const Scaleform::Render::Text::ParagraphFormat *)&v9[1].ResolveHandler.Flags,
                v12,
                v12 + 1);
              Scaleform::GFx::TextField::SetDirtyFlag(v2);
            }
          }
        }
      }
      else if ( NArgs >= 3 )
      {
        v23 = fn->Env;
        v13 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        v14 = Scaleform::GFx::AS2::Value::ToObject(v13, v23);
        v15 = v14;
        if ( v14 )
        {
          if ( v14->GetObjectType(&v14->Scaleform::GFx::AS2::ObjectInterface) == Object_TextFormat )
          {
            v24 = fn->Env;
            v16 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
            v17 = Scaleform::GFx::AS2::Value::ToNumber(v16, v24);
            if ( v17 < 0.0 )
              v17 = 0.0;
            startPos = v17;
            v25 = fn->Env;
            v18 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
            v19 = Scaleform::GFx::AS2::Value::ToNumber(v18, v25);
            if ( v19 < 0.0 )
              v19 = 0.0;
            if ( startPos <= v19 )
            {
              v20 = (__int64)startPos;
              Scaleform::Render::Text::DocView::SetTextFormat(
                v2->pDocument.pObject,
                (const Scaleform::Render::Text::TextFormat *)&v15[1],
                v20,
                (__int64)v19);
              Scaleform::Render::Text::DocView::SetParagraphFormat(
                v2->pDocument.pObject,
                (const Scaleform::Render::Text::ParagraphFormat *)&v15[1].ResolveHandler.Flags,
                v20,
                (__int64)v19);
              Scaleform::GFx::TextField::SetDirtyFlag(v2);
            }
          }
        }
      }
    }
  }
}
