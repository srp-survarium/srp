void __cdecl Scaleform::GFx::AS2::AvmTextField::AppendText(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::TextField *v3; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::ASStringNode *v5; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-14h]

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = v1->ThisPtr;
    if ( (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 )
      v3 = 0;
    else
      v3 = (Scaleform::GFx::TextField *)ThisPtr[1].__vftable;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v3) && v1->NArgs >= 1 )
    {
      Env = v1->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v4, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
      v5 = (Scaleform::GFx::ASStringNode *)fn;
      Scaleform::GFx::TextField::AppendText(v3, (const char *)fn->__vftable, 0xFFFFFFFF);
      Scaleform::GFx::TextField::SetDirtyFlag(v3);
      if ( v5->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    }
  }
}
