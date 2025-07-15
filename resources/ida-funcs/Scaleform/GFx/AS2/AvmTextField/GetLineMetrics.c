void __cdecl Scaleform::GFx::AS2::AvmTextField::GetLineMetrics(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v2; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  long double v4; // st7
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::Object *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // ebp
  Scaleform::GFx::AS2::Environment *v9; // ecx
  Scaleform::GFx::AS2::Environment *v10; // ecx
  Scaleform::GFx::AS2::Environment *v11; // ecx
  Scaleform::GFx::AS2::Environment *v12; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::ASStringNode *p_StringContext; // [esp-14h] [ebp-44h]
  Scaleform::GFx::ASStringNode *v16; // [esp-14h] [ebp-44h]
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-34h]
  Scaleform::GFx::AS2::Value v18; // [esp+4h] [ebp-2Ch] BYREF
  Scaleform::Render::Text::DocView::LineMetrics v19; // [esp+18h] [ebp-18h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = fn->ThisPtr;
    v2 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 ? 0 : ThisPtr[1].__vftable;
    if ( fn->NArgs >= 1 )
    {
      Env = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v4 = Scaleform::GFx::AS2::Value::ToNumber(v3, Env);
      if ( (int)v4 >= 0
        && Scaleform::Render::Text::DocView::GetLineMetrics(
             (Scaleform::Render::Text::DocView *)v2[1].GetMemberRaw,
             (int)v4,
             &v19) )
      {
        pHeap = fn->Env->StringContext.pContext->pHeap;
        v6 = (Scaleform::GFx::AS2::Object *)pHeap->Alloc(pHeap, 52u, 0);
        if ( v6 )
        {
          Scaleform::GFx::AS2::Object::Object(v6, fn->Env);
          v8 = v7;
        }
        else
        {
          v8 = 0;
        }
        v18.V.BooleanValue = 3;
        v9 = fn->Env;
        *(double *)((char *)&v18.NV.NumberValue + 4) = (double)v19.Ascent * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&v9->StringContext,
          "ascent",
          (const Scaleform::GFx::AS2::Value *)&v18.NV.4);
        if ( v18.V.BooleanValue >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v18.NV.4);
        v18.V.BooleanValue = 3;
        v10 = fn->Env;
        *(double *)((char *)&v18.NV.NumberValue + 4) = (double)v19.Descent * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&v10->StringContext,
          "descent",
          (const Scaleform::GFx::AS2::Value *)&v18.NV.4);
        if ( v18.V.BooleanValue >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v18.NV.4);
        v18.V.BooleanValue = 3;
        v11 = fn->Env;
        *(double *)((char *)&v18.NV.NumberValue + 4) = (double)v19.Width * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&v11->StringContext,
          "width",
          (const Scaleform::GFx::AS2::Value *)&v18.NV.4);
        if ( v18.V.BooleanValue >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v18.NV.4);
        v18.V.BooleanValue = 3;
        v12 = fn->Env;
        *(double *)((char *)&v18.NV.NumberValue + 4) = (double)v19.Height * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&v12->StringContext,
          "height",
          (const Scaleform::GFx::AS2::Value *)&v18.NV.4);
        if ( v18.V.BooleanValue >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v18.NV.4);
        p_StringContext = (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext;
        *(double *)((char *)&v18.NV.NumberValue + 4) = (double)v19.Leading * 0.05;
        v18.V.BooleanValue = 3;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          p_StringContext,
          "leading",
          (const Scaleform::GFx::AS2::Value *)&v18.NV.4);
        if ( v18.V.BooleanValue >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v18.NV.4);
        v16 = (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext;
        *(double *)((char *)&v18.NV.NumberValue + 4) = (double)v19.FirstCharXOff * 0.05;
        v18.V.BooleanValue = 3;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          v16,
          "x",
          (const Scaleform::GFx::AS2::Value *)&v18.NV.4);
        if ( v18.V.BooleanValue >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v18.NV.4);
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v8);
        if ( v8 )
        {
          RefCount = v8->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v8->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
          }
        }
      }
      else
      {
        Result = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 0;
      }
    }
  }
}
