Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::Add(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::StringManager *sm,
        Scaleform::GFx::AS3::Value *resulta,
        Scaleform::GFx::AS3::Value *l,
        Scaleform::GFx::AS3::Value *r)
{
  Scaleform::GFx::AS3::Value *v5; // esi
  Scaleform::GFx::AS3::Value *v6; // edi
  int v7; // ecx
  Scaleform::GFx::AS3::CheckResult *v8; // eax
  Scaleform::GFx::AS3::CheckResult *v9; // esi
  const Scaleform::GFx::ASString *v; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::CheckResult *v12; // esi
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::AS3::CheckResult v15; // [esp+27h] [ebp-31h] BYREF
  double v16; // [esp+28h] [ebp-30h] BYREF
  double r_num; // [esp+30h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value r_prim; // [esp+38h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value l_prim; // [esp+48h] [ebp-10h] BYREF

  LODWORD(r_num) = 0;
  v5 = l;
  v6 = r;
  if ( (l->Flags & 0x1F) - 12 <= 3 && (r->Flags & 0x1F) - 12 <= 3 )
  {
    if ( l->value.VS._1.VInt )
    {
      if ( r->value.VS._1.VInt )
      {
        v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(l->value.VS._1.VInt + 20) + 64) + 36);
        if ( (*(unsigned __int8 (__thiscall **)(int, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value::V1U))(*(_DWORD *)v7 + 40))(
               v7,
               resulta,
               l->value.VS._1,
               r->value.VS._1) )
        {
          goto LABEL_13;
        }
      }
    }
  }
  if ( (v5->Flags & 0x1F) == 0xA || (v6->Flags & 0x1F) == 0xA )
  {
    LODWORD(r_num) = &sm->pStringManager->EmptyStringNode;
    ++*(_DWORD *)(LODWORD(r_num) + 12);
    LODWORD(v16) = &sm->pStringManager->EmptyStringNode;
    ++*(_DWORD *)(LODWORD(v16) + 12);
    if ( Scaleform::GFx::AS3::Value::Convert2String(
           v5,
           (Scaleform::GFx::AS3::CheckResult *)&l,
           (Scaleform::GFx::ASString *)&r_num)->Result
      && Scaleform::GFx::AS3::Value::Convert2String(v6, &v15, (Scaleform::GFx::ASString *)&v16)->Result )
    {
      v = Scaleform::GFx::ASString::operator+(
            (Scaleform::GFx::ASString *)&r_num,
            (Scaleform::GFx::ASString *)&l,
            (const Scaleform::GFx::ASString *)&v16);
      Scaleform::GFx::AS3::Value::Assign(resulta, v);
      v11 = (Scaleform::GFx::ASStringNode *)l;
      --l->value.VS._2.VObj;
      if ( !v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      v12 = result;
      result->Result = 1;
    }
    else
    {
      v12 = result;
      result->Result = 0;
    }
    v13 = (Scaleform::GFx::ASStringNode *)LODWORD(v16);
    --*(_DWORD *)(LODWORD(v16) + 12);
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v14 = (Scaleform::GFx::ASStringNode *)LODWORD(r_num);
    --*(_DWORD *)(LODWORD(r_num) + 12);
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    return v12;
  }
  else if ( (v5->Flags & 0x1F) >= 5 || (v6->Flags & 0x1F) >= 5 )
  {
    l_prim.Flags = 0;
    l_prim.Bonus.pWeakProxy = 0;
    r_prim.Flags = 0;
    r_prim.Bonus.pWeakProxy = 0;
    if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(
           v5,
           (Scaleform::GFx::AS3::CheckResult *)&l,
           &l_prim,
           hintNone)->Result
      && Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(v6, &v15, &r_prim, hintNone)->Result )
    {
      v9 = result;
      Scaleform::GFx::AS3::Add(result, sm, resulta, &l_prim, &r_prim);
    }
    else
    {
      v9 = result;
      result->Result = 0;
    }
    Scaleform::GFx::AS3::Value::~Value(&r_prim);
    Scaleform::GFx::AS3::Value::~Value(&l_prim);
    return v9;
  }
  else
  {
    v16 = 0.0;
    r_num = 0.0;
    if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(v5, (Scaleform::GFx::AS3::CheckResult *)&l, &v16)->Result
      && Scaleform::GFx::AS3::Value::Convert2NumberInline(v6, &v15, &r_num)->Result )
    {
      Scaleform::GFx::AS3::Value::SetNumber(resulta, r_num + v16);
LABEL_13:
      v8 = result;
      result->Result = 1;
      return v8;
    }
    v8 = result;
    result->Result = 0;
  }
  return v8;
}
