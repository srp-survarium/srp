void __cdecl Scaleform::GFx::AS2::AvmTextField::SetNewTextFormat(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::TextField *v2; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Object *v4; // eax
  Scaleform::GFx::AS2::Object *v5; // esi
  Scaleform::Render::Text::DocView::DocumentText *pObject; // eax
  Scaleform::Render::Text::ParagraphFormat *v7; // ebx
  Scaleform::Render::Text::TextFormat *v8; // eax
  const Scaleform::Render::Text::ParagraphFormat *v9; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-34h]
  Scaleform::Render::Text::TextFormat result; // [esp+4h] [ebp-28h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = fn->ThisPtr;
    if ( (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 )
      v2 = 0;
    else
      v2 = (Scaleform::GFx::TextField *)ThisPtr[1].__vftable;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v2) && fn->NArgs >= 1 )
    {
      Env = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v4 = Scaleform::GFx::AS2::Value::ToObject(v3, Env);
      v5 = v4;
      if ( v4 )
      {
        if ( v4->GetObjectType(&v4->Scaleform::GFx::AS2::ObjectInterface) == Object_TextFormat )
        {
          pObject = v2->pDocument.pObject->pDocument.pObject;
          v7 = pObject->pDefaultParagraphFormat.pObject;
          v8 = Scaleform::Render::Text::TextFormat::Merge(
                 pObject->pDefaultTextFormat.pObject,
                 &result,
                 (const Scaleform::Render::Text::TextFormat *)&v5[1]);
          Scaleform::GFx::TextField::SetDefaultTextFormat(v2, v8);
          Scaleform::Render::Text::TextFormat::~TextFormat(&result);
          v9 = Scaleform::Render::Text::ParagraphFormat::Merge(
                 v7,
                 (Scaleform::Render::Text::ParagraphFormat *)&result,
                 (const Scaleform::Render::Text::ParagraphFormat *)&v5[1].ResolveHandler.Flags);
          Scaleform::GFx::TextField::SetDefaultParagraphFormat(v2, v9);
          Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)&result);
        }
      }
    }
  }
}
