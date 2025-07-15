void __cdecl Scaleform::GFx::AS2::AvmTextField::PasteFromClipboard(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::Render::Text::EditorKitBase *pObject; // ebx
  Scaleform::Render::Text::EditorKitBase_vtbl *v4; // eax
  Scaleform::String::DataDesc *GetCompositionString; // edx
  unsigned int v6; // ecx
  Scaleform::String::DataDesc *v7; // edi
  Scaleform::String v8; // ebp
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::AS2::Value *v10; // eax
  Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-18h]
  Scaleform::GFx::AS2::Environment *v13; // [esp-10h] [ebp-18h]
  Scaleform::GFx::AS2::Environment *v14; // [esp-10h] [ebp-18h]
  unsigned int v15; // [esp+4h] [ebp-4h]
  Scaleform::GFx::TextField *v16; // [esp+Ch] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = fn->ThisPtr;
    v16 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3
        ? 0
        : (Scaleform::GFx::TextField *)ThisPtr[1].__vftable;
    pObject = v16->pDocument.pObject->pEditorKit.pObject;
    if ( pObject )
    {
      LOBYTE(v15) = ((int)pObject[16].__vftable & 4) != 0;
      v4 = pObject[1].__vftable;
      GetCompositionString = (Scaleform::String::DataDesc *)v4->GetCompositionString;
      v6 = (unsigned int)v4[1].~Scaleform::Render::Text::EditorKitBase;
      v7 = GetCompositionString;
      if ( (unsigned int)GetCompositionString >= v6 )
        v7 = (Scaleform::String::DataDesc *)v4[1].~Scaleform::Render::Text::EditorKitBase;
      v8.pData = (Scaleform::String::DataDesc *)v4->GetCompositionString;
      if ( v6 >= (unsigned int)GetCompositionString )
        v8.pData = (Scaleform::String::DataDesc *)v4[1].~Scaleform::Render::Text::EditorKitBase;
      if ( fn->NArgs >= 1 )
      {
        Env = fn->Env;
        v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        LOBYTE(v15) = Scaleform::GFx::AS2::Value::ToBool(v9, (int)v7, Env);
      }
      if ( fn->NArgs >= 2 )
      {
        v13 = fn->Env;
        v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v7 = (Scaleform::String::DataDesc *)Scaleform::GFx::AS2::Value::ToUInt32(v10, v13);
      }
      if ( fn->NArgs >= 3 )
      {
        v14 = fn->Env;
        v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        v8.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::AS2::Value::ToUInt32(v11, v14);
      }
      Scaleform::GFx::Text::EditorKit::PasteFromClipboard((Scaleform::GFx::Text::EditorKit *)pObject, v7, v8, v15);
      Scaleform::GFx::TextField::SetDirtyFlag(v16);
    }
  }
}
