void __cdecl Scaleform::GFx::AS2::AvmTextField::CutToClipboard(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::Render::Text::EditorKitBase *pObject; // ebx
  Scaleform::Render::Text::EditorKitBase_vtbl *v4; // eax
  Scaleform::Render::Text::Paragraph *GetCompositionString; // edx
  unsigned int v6; // ecx
  Scaleform::Render::Text::Paragraph *v7; // edi
  Scaleform::Render::Text::Paragraph *v8; // ebp
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::AS2::Value *v10; // eax
  Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-18h]
  Scaleform::GFx::AS2::Environment *v13; // [esp-10h] [ebp-18h]
  Scaleform::GFx::AS2::Environment *v14; // [esp-10h] [ebp-18h]
  char richClipboard; // [esp+4h] [ebp-4h]
  Scaleform::GFx::TextField *fna; // [esp+Ch] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = fn->ThisPtr;
    fna = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3
        ? 0
        : (Scaleform::GFx::TextField *)ThisPtr[1].__vftable;
    pObject = fna->pDocument.pObject->pEditorKit.pObject;
    if ( pObject )
    {
      richClipboard = ((int)pObject[16].__vftable & 4) != 0;
      v4 = pObject[1].__vftable;
      GetCompositionString = (Scaleform::Render::Text::Paragraph *)v4->GetCompositionString;
      v6 = (unsigned int)v4[1].~Scaleform::Render::Text::EditorKitBase;
      v7 = GetCompositionString;
      if ( (unsigned int)GetCompositionString >= v6 )
        v7 = (Scaleform::Render::Text::Paragraph *)v4[1].~Scaleform::Render::Text::EditorKitBase;
      v8 = (Scaleform::Render::Text::Paragraph *)v4->GetCompositionString;
      if ( v6 >= (unsigned int)GetCompositionString )
        v8 = (Scaleform::Render::Text::Paragraph *)v4[1].~Scaleform::Render::Text::EditorKitBase;
      if ( fn->NArgs >= 1 )
      {
        Env = fn->Env;
        v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        richClipboard = Scaleform::GFx::AS2::Value::ToBool(v9, Env);
      }
      if ( fn->NArgs >= 2 )
      {
        v13 = fn->Env;
        v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v7 = (Scaleform::Render::Text::Paragraph *)Scaleform::GFx::AS2::Value::ToUInt32(v10, v13);
      }
      if ( fn->NArgs >= 3 )
      {
        v14 = fn->Env;
        v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        v8 = (Scaleform::Render::Text::Paragraph *)Scaleform::GFx::AS2::Value::ToUInt32(v11, v14);
      }
      Scaleform::GFx::Text::EditorKit::CutToClipboard((Scaleform::GFx::Text::EditorKit *)pObject, v7, v8, richClipboard);
      Scaleform::GFx::TextField::SetDirtyFlag(fna);
    }
  }
}
