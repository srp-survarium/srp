char __thiscall Scaleform::GFx::AS2::ActionBuffer::ResolveFrameNumber(
        Scaleform::GFx::AS2::ActionBuffer *this,
        Scaleform::GFx::AS2::Environment *env,
        Scaleform::GFx::ASStringNode *frameValue,
        Scaleform::GFx::InteractiveObject **pptarget,
        unsigned int *pframeNumber)
{
  unsigned __int8 pData; // al
  Scaleform::GFx::InteractiveObject *Target; // ebx
  char v7; // dl
  int Length; // ebp
  const char *v9; // esi
  Scaleform::GFx::ASStringNode *v10; // edi
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // esi
  Scaleform::GFx::ASStringNode *v13; // ecx
  Scaleform::GFx::AS2::Value::NumericType *p_RefCount; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  long double v17; // st7
  bool success; // [esp+Dh] [ebp-9h]
  Scaleform::GFx::ASString targetStr; // [esp+Eh] [ebp-8h] BYREF

  pData = (unsigned __int8)frameValue->pData;
  Target = env->Target;
  v7 = 0;
  success = 0;
  if ( LOBYTE(frameValue->pData) == 5 )
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(
      (Scaleform::GFx::AS2::Value *)frameValue,
      (Scaleform::GFx::ASString *)&frameValue,
      env,
      -1,
      0);
    Length = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&frameValue);
    v9 = 0;
    if ( Length <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      if ( Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&frameValue, v9) == 58 )
      {
        v10 = Scaleform::GFx::ASConstString::SubstringNode((Scaleform::GFx::ASConstString *)&frameValue, 0, v9);
        ++v10->RefCount;
        targetStr.pNode = v10;
        Target = Scaleform::GFx::AS2::Environment::FindTarget(env, &targetStr, 0);
        if ( Target )
        {
          if ( (int)v9 < Length )
          {
            v12 = Scaleform::GFx::ASConstString::SubstringNode(
                    (Scaleform::GFx::ASConstString *)&frameValue,
                    v9 + 1,
                    (const char *)(Length + 1));
            v12->RefCount += 2;
            v13 = frameValue;
            p_RefCount = (Scaleform::GFx::AS2::Value::NumericType *)&frameValue->RefCount;
            --frameValue->RefCount;
            if ( !*(_DWORD *)&p_RefCount->Type )
              Scaleform::GFx::ASStringNode::ReleaseNode(v13);
            frameValue = v12;
            v11 = v12->RefCount-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v12);
            v11 = v10->RefCount-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v10);
LABEL_17:
            if ( Target && Target->GetLabeledFrame(Target, frameValue->pData, pframeNumber, 1) )
            {
              v7 = 1;
              success = 1;
            }
            else
            {
              v7 = 0;
            }
            v15 = frameValue;
            --frameValue->RefCount;
            if ( !v15->RefCount )
            {
              Scaleform::GFx::ASStringNode::ReleaseNode(v15);
              v7 = success;
            }
            if ( v7 )
            {
LABEL_24:
              if ( pptarget )
                *pptarget = Target;
            }
            return v7;
          }
          Target = 0;
        }
        v11 = v10->RefCount-- == 1;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      }
      if ( (int)++v9 >= Length )
        goto LABEL_17;
    }
  }
  if ( pData != 6 && (pData == 3 || pData == 4) )
  {
    v17 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)frameValue, env);
    frameValue = (Scaleform::GFx::ASStringNode *)((unsigned __int16)env | 0xC00);
    v7 = 1;
    *pframeNumber = (__int64)(v17 - 1.0);
    goto LABEL_24;
  }
  return v7;
}
