Scaleform::GFx::ASString *__usercall Scaleform::GFx::AS3::GetVTableIndName@<eax>(
        int ind@<edi>,
        Scaleform::String isClosure@<ecx>,
        Scaleform::GFx::ASString *a3@<esi>,
        Scaleform::GFx::ASString base,
        Scaleform::GFx::AS3::VTable *vt)
{
  const Scaleform::GFx::AS3::VTable *v5; // ebx
  Scaleform::GFx::AS3::Value *v6; // eax
  Scaleform::GFx::ASString *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // [esp-Ch] [ebp-10h]
  const Scaleform::GFx::AS3::ThunkInfo *VThunk; // [esp-8h] [ebp-Ch]

  v5 = vt;
  v6 = &vt->VTMethods.Data.Data[ind];
  if ( (v6->Flags & 0x1F) == 6 )
  {
    if ( LOBYTE(isClosure.pData) )
      Scaleform::GFx::ASString::operator=(&base, (Scaleform::GFx::ASStringNode *)"MethodClosure ");
    else
      Scaleform::GFx::ASString::operator=(&base, (Scaleform::GFx::ASStringNode *)"Function ");
    v7 = Scaleform::GFx::ASString::operator+(&base, (Scaleform::GFx::ASString *)&vt, &v5->Names.Data.Data[ind]);
    Scaleform::GFx::ASString::operator+(v7, a3, (const __m128i *)"()");
    v8 = (Scaleform::GFx::ASStringNode *)vt;
    --vt->VTMethods.Data.Policy.Capacity;
    if ( !v8->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  else
  {
    VThunk = v6->value.VS._1.VThunk;
    pNode = base.pNode;
    ++base.pNode->RefCount;
    Scaleform::GFx::AS3::GetThunkName(a3, (Scaleform::GFx::ASString)pNode, VThunk, isClosure);
  }
  v9 = base.pNode;
  --base.pNode->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  return a3;
}
