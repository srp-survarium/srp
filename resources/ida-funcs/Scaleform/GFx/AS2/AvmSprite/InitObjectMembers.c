void __cdecl Scaleform::GFx::AS2::AvmSprite::InitObjectMembers(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *v2; // esi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v5; // eax
  Scaleform::GFx::AS2::ObjectInterface *v6; // ecx
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::AvmSprite::InitObjectMembers::__l4::InitVisitor memberVisitor; // [esp+10h] [ebp-Ch] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr->GetObjectType(ThisPtr) == Object_Sprite )
  {
    v2 = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
    if ( v2 )
    {
      ++v2->RefCount;
      Env = fn->Env;
      v4 = 0;
      if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1)
                                    + Env->Stack.pCurrent
                                    - Env->Stack.pPageStart )
        v4 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                           & 0x1F];
      if ( v4->T.Type == 7 )
      {
        v5 = Scaleform::GFx::AS2::Value::ToAvmCharacter(v4, Env);
        if ( v5 )
        {
          v6 = &v5->Scaleform::GFx::AS2::ObjectInterface;
LABEL_11:
          memberVisitor.pEnv = fn->Env;
          memberVisitor.__vftable = (Scaleform::GFx::AS2::AvmSprite::InitObjectMembers::__l4::InitVisitor_vtbl *)&`Scaleform::GFx::AS2::AvmSprite::InitObjectMembers'::`4'::InitVisitor::`vftable';
          memberVisitor.pCharacter = v2;
          v6->VisitMembers(v6, &memberVisitor.pEnv->StringContext, &memberVisitor, 0, 0);
          memberVisitor.__vftable = (Scaleform::GFx::AS2::AvmSprite::InitObjectMembers::__l4::InitVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
          Scaleform::RefCountNTSImpl::Release(v2);
          return;
        }
      }
      else
      {
        v7 = Scaleform::GFx::AS2::Value::ToObject(v4, Env);
        if ( v7 )
        {
          v6 = &v7->Scaleform::GFx::AS2::ObjectInterface;
          goto LABEL_11;
        }
      }
      v6 = 0;
      goto LABEL_11;
    }
  }
}
