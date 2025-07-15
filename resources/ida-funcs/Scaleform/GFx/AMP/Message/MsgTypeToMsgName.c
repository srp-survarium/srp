Scaleform::String *__cdecl Scaleform::GFx::AMP::Message::MsgTypeToMsgName(
        Scaleform::String *result,
        Scaleform::String msgType)
{
  Scaleform::String *v2; // esi
  const Scaleform::String *StaticTypeName; // eax
  Scaleform::String *v4; // eax
  const Scaleform::String *v5; // eax
  const Scaleform::String *v6; // eax
  const Scaleform::String *v7; // eax
  const Scaleform::String *v8; // eax
  const Scaleform::String *v9; // eax
  const Scaleform::String *v10; // eax
  const Scaleform::String *v11; // eax
  const Scaleform::String *v12; // eax
  const Scaleform::String *v13; // eax
  const Scaleform::String *v14; // eax
  const Scaleform::String *v15; // eax
  const Scaleform::String *v16; // eax
  const Scaleform::String *v17; // eax
  const Scaleform::String *v18; // eax
  const Scaleform::String *v19; // eax
  const Scaleform::String *v20; // eax
  const Scaleform::String *v21; // eax
  Scaleform::String v22; // [esp+4h] [ebp-40h] BYREF
  Scaleform::String v23; // [esp+8h] [ebp-3Ch] BYREF
  Scaleform::String v24; // [esp+Ch] [ebp-38h] BYREF
  Scaleform::String v25; // [esp+10h] [ebp-34h] BYREF
  Scaleform::String v26; // [esp+14h] [ebp-30h] BYREF
  Scaleform::String v27; // [esp+18h] [ebp-2Ch] BYREF
  Scaleform::String v28; // [esp+1Ch] [ebp-28h] BYREF
  Scaleform::String v29; // [esp+20h] [ebp-24h] BYREF
  Scaleform::String v30; // [esp+24h] [ebp-20h] BYREF
  Scaleform::String v31; // [esp+28h] [ebp-1Ch] BYREF
  Scaleform::String v32; // [esp+2Ch] [ebp-18h] BYREF
  Scaleform::String v33; // [esp+30h] [ebp-14h] BYREF
  Scaleform::String v34; // [esp+34h] [ebp-10h] BYREF
  Scaleform::String v35; // [esp+38h] [ebp-Ch] BYREF
  Scaleform::String v36; // [esp+3Ch] [ebp-8h] BYREF
  Scaleform::String v37; // [esp+40h] [ebp-4h] BYREF

  v2 = result;
  Scaleform::String::String(result);
  switch ( msgType.HeapTypeBits )
  {
    case 1u:
      StaticTypeName = Scaleform::GFx::AMP::MessageHeartbeat::GetStaticTypeName((Scaleform::String *)&result);
      Scaleform::String::operator=(v2, StaticTypeName);
      Scaleform::String::~String((Scaleform::String *)&result);
      v4 = v2;
      break;
    case 2u:
      v5 = Scaleform::GFx::AMP::MessageLog::GetStaticTypeName(&msgType);
      Scaleform::String::operator=(v2, v5);
      Scaleform::String::~String(&msgType);
      v4 = v2;
      break;
    case 3u:
      v6 = Scaleform::GFx::AMP::MessageCurrentState::GetStaticTypeName(&v22);
      Scaleform::String::operator=(v2, v6);
      Scaleform::String::~String(&v22);
      v4 = v2;
      break;
    case 4u:
      v7 = Scaleform::GFx::AMP::MessageProfileFrame::GetStaticTypeName(&v23);
      Scaleform::String::operator=(v2, v7);
      Scaleform::String::~String(&v23);
      v4 = v2;
      break;
    case 5u:
      v8 = Scaleform::GFx::AMP::MessageSwdFile::GetStaticTypeName(&v24);
      Scaleform::String::operator=(v2, v8);
      Scaleform::String::~String(&v24);
      v4 = v2;
      break;
    case 6u:
      v9 = Scaleform::GFx::AMP::MessageSourceFile::GetStaticTypeName(&v25);
      Scaleform::String::operator=(v2, v9);
      Scaleform::String::~String(&v25);
      v4 = v2;
      break;
    case 7u:
      v11 = Scaleform::GFx::AMP::MessageSwdRequest::GetStaticTypeName(&v27);
      Scaleform::String::operator=(v2, v11);
      Scaleform::String::~String(&v27);
      v4 = v2;
      break;
    case 8u:
      v12 = Scaleform::GFx::AMP::MessageSourceRequest::GetStaticTypeName(&v28);
      Scaleform::String::operator=(v2, v12);
      Scaleform::String::~String(&v28);
      v4 = v2;
      break;
    case 9u:
      v14 = Scaleform::GFx::AMP::MessageAppControl::GetStaticTypeName(&v30);
      Scaleform::String::operator=(v2, v14);
      Scaleform::String::~String(&v30);
      v4 = v2;
      break;
    case 0xAu:
      v16 = Scaleform::GFx::AMP::MessagePort::GetStaticTypeName(&v32);
      Scaleform::String::operator=(v2, v16);
      Scaleform::String::~String(&v32);
      v4 = v2;
      break;
    case 0xBu:
      v17 = Scaleform::GFx::AMP::MessageImageRequest::GetStaticTypeName(&v33);
      Scaleform::String::operator=(v2, v17);
      Scaleform::String::~String(&v33);
      v4 = v2;
      break;
    case 0xCu:
      v18 = Scaleform::GFx::AMP::MessageImageData::GetStaticTypeName(&v34);
      Scaleform::String::operator=(v2, v18);
      Scaleform::String::~String(&v34);
      v4 = v2;
      break;
    case 0xDu:
      v19 = Scaleform::GFx::AMP::MessageFontRequest::GetStaticTypeName(&v35);
      Scaleform::String::operator=(v2, v19);
      Scaleform::String::~String(&v35);
      v4 = v2;
      break;
    case 0xEu:
      v20 = Scaleform::GFx::AMP::MessageFontData::GetStaticTypeName(&v36);
      Scaleform::String::operator=(v2, v20);
      Scaleform::String::~String(&v36);
      v4 = v2;
      break;
    case 0xFu:
      v21 = Scaleform::GFx::AMP::MessageCompressed::GetStaticTypeName(&v37);
      Scaleform::String::operator=(v2, v21);
      Scaleform::String::~String(&v37);
      goto LABEL_20;
    case 0x10u:
      v15 = Scaleform::GFx::AMP::MessageInitState::GetStaticTypeName(&v31);
      Scaleform::String::operator=(v2, v15);
      Scaleform::String::~String(&v31);
      v4 = v2;
      break;
    case 0x11u:
      v13 = Scaleform::GFx::AMP::MessageObjectsReportRequest::GetStaticTypeName(&v29);
      Scaleform::String::operator=(v2, v13);
      Scaleform::String::~String(&v29);
      v4 = v2;
      break;
    case 0x12u:
      v10 = Scaleform::GFx::AMP::MessageObjectsReport::GetStaticTypeName(&v26);
      Scaleform::String::operator=(v2, v10);
      Scaleform::String::~String(&v26);
      v4 = v2;
      break;
    default:
LABEL_20:
      v4 = v2;
      break;
  }
  return v4;
}
