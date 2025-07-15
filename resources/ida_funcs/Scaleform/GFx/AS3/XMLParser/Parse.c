Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::XMLParser::Parse(
        Scaleform::GFx::AS3::XMLParser *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::StringDataPtr *str,
        unsigned int *pos,
        bool isList)
{
  int v6; // esi
  int v8; // eax
  int ErrorCode; // eax
  Scaleform::GFx::AS3::XMLParser::Kind v10; // ecx
  Scaleform::GFx::AS3::VM::ErrorID v11; // ebx
  char v12; // dl
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx
  unsigned int v14; // eax
  unsigned int v15; // ecx
  const char *pStr; // ebp
  Scaleform::GFx::AS3::CheckResult *v17; // eax
  Scaleform::GFx::AS3::VM *v18; // esi
  const Scaleform::GFx::AS3::VM::Error *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  char rc; // [esp+13h] [ebp-9h]
  Scaleform::GFx::AS3::VM *vm; // [esp+14h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v23; // [esp+18h] [ebp-4h]
  char shouldAdvancePos; // [esp+24h] [ebp+8h]

  v6 = *pos;
  v8 = XML_Parse((int)this->Parser, (unsigned __int8 *)&str->pStr[*pos], str->Size - *pos, 1);
  rc = v8 == 1;
  shouldAdvancePos = 1;
  if ( v8 == 1 )
    goto LABEL_33;
  ErrorCode = XML_GetErrorCode(this->Parser);
  v10 = kNone;
  vm = this->ITr->pVM;
  v11 = eXMLMalformedElement;
  if ( this->KindStack.Data.Size )
    v10 = this->KindStack.Data.Data[this->KindStack.Data.Size - 1];
  v12 = 1;
  switch ( ErrorCode )
  {
    case 0:
      if ( *pos != v6 )
        goto LABEL_30;
      pObject = this->pCurrElem.pObject;
      if ( !pObject )
        goto LABEL_30;
      if ( pObject->GetKind(pObject) != kInstruction )
        goto LABEL_30;
      v14 = 0;
      v15 = str->Size - v6;
      if ( !v15 )
        goto LABEL_30;
      pStr = str->pStr;
      break;
    case 1:
      v11 = eOutOfMemoryError;
      goto LABEL_30;
    case 3:
      if ( isList )
      {
        shouldAdvancePos = 0;
        v12 = 0;
      }
      if ( this->pCurrElem.pObject )
      {
        if ( v10 == kElement )
        {
          v11 = eXMLUnterminatedElementTag;
          if ( v12 )
            goto LABEL_30;
        }
      }
      goto LABEL_32;
    case 4:
      if ( !this->pCurrElem.pObject )
        goto LABEL_33;
      goto LABEL_30;
    case 5:
      v11 = eXMLUnterminatedProcessingInstruction;
      goto LABEL_30;
    case 7:
      if ( v10 == kElement )
        v11 = eXMLUnterminatedElementTag;
      goto LABEL_30;
    case 8:
      v11 = eXMLDuplicateAttribute;
      goto LABEL_30;
    case 9:
      if ( isList )
      {
        rc = 1;
        goto LABEL_33;
      }
      if ( this->pCurrElem.pObject && v10 == kElement )
        v11 = eXMLUnterminatedElementTag;
      else
        v11 = eXMLMarkupMustBeWellFormed;
      goto LABEL_30;
    case 20:
      v11 = eXMLUnterminatedCData;
      goto LABEL_30;
    case 35:
      goto $LN86_3;
    default:
      goto LABEL_30;
  }
  do
  {
    if ( pStr[v14] == 63 && v14 + 1 < v15 && pStr[v14 + 1] == 62 )
    {
      *pos += v14 + 2;
      v17 = result;
      result->Result = 1;
      return v17;
    }
    ++v14;
  }
  while ( v14 < v15 );
LABEL_30:
  v18 = vm;
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&vm, v11, vm);
  Scaleform::GFx::AS3::VM::ThrowTypeError(v18, v19);
  v20 = v23;
  --v23->RefCount;
  if ( !v20->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
LABEL_32:
  if ( shouldAdvancePos )
LABEL_33:
    *pos += XML_GetCurrentByteIndex(this->Parser);
$LN86_3:
  Scaleform::GFx::AS3::XMLParser::SetNodeKind(this, kNone);
  v17 = result;
  result->Result = rc;
  return v17;
}
