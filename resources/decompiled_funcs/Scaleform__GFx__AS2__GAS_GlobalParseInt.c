void __cdecl Scaleform::GFx::AS2::GAS_GlobalParseInt(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v3; // ecx
  unsigned int v4; // ebx
  Scaleform::GFx::ASStringNode *pNode; // ebp
  int v6; // esi
  Scaleform::GFx::AS2::Value *v7; // eax
  int v8; // eax
  Scaleform::GFx::AS2::Value *v9; // edi
  char v11; // al
  Scaleform::GFx::ASStringNode *pData; // ecx
  Scaleform::GFx::AS2::Value *v13; // edi
  int v14; // ecx
  const char *v15; // [esp-18h] [ebp-28h]
  Scaleform::GFx::AS2::Environment *v16; // [esp-10h] [ebp-20h]
  Scaleform::GFx::ASString str; // [esp+4h] [ebp-Ch] BYREF
  double result; // [esp+8h] [ebp-8h]

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    v3 = 0;
    v4 = 10;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v3 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    Scaleform::GFx::AS2::Value::ToStringImpl(v3, &str, Env, -1, 0);
    pNode = str.pNode;
    v6 = 0;
    if ( v1->NArgs < 2 )
    {
      if ( str.pNode->Size > 1 && *str.pNode->pData == 48 )
      {
        v11 = *((_BYTE *)str.pNode->pData + 1);
        v6 = 1;
        v4 = 8;
        if ( v11 == 120 || v11 == 88 )
        {
          v4 = 16;
          v6 = 2;
        }
      }
    }
    else
    {
      v16 = v1->Env;
      v7 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      v8 = Scaleform::GFx::AS2::Value::ToInt32(v7, v16);
      v4 = v8;
      if ( v8 < 2 || v8 > 36 )
        goto LABEL_7;
    }
    pData = (Scaleform::GFx::ASStringNode *)pNode->pData;
    fn = 0;
    v15 = &pNode->pData[v6];
    str.pNode = pData;
    LODWORD(result) = strtol(v4, v15, (char **)&fn, v4);
    if ( (const Scaleform::GFx::AS2::FnCall *)((char *)str.pNode + v6) != fn || v4 == 8 )
    {
      v13 = v1->Result;
      if ( v13->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v13);
      v14 = LODWORD(result);
      v13->T.Type = 4;
      v13->NV.Int32Value = v14;
      goto LABEL_10;
    }
LABEL_7:
    result = Scaleform::GFx::NumberUtil::NaN();
    v9 = v1->Result;
    if ( v9->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v9);
    v9->NV.NumberValue = result;
    v9->T.Type = 3;
LABEL_10:
    if ( pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
