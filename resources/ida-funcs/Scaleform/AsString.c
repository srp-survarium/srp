Scaleform::String *__cdecl Scaleform::AsString<long>(Scaleform::String *result, int *v)
{
  Scaleform::MsgFormat::Sink v3; // [esp+4h] [ebp-Ch] BYREF

  Scaleform::String::String(result);
  v3.Type = tStr;
  v3.SinkData.pStr = result;
  Scaleform::Format<long>(&v3, "{0}", v);
  return result;
}


Scaleform::String *__cdecl Scaleform::AsString<unsigned long>(Scaleform::String *result, const unsigned int *v)
{
  Scaleform::MsgFormat::Sink v3; // [esp+4h] [ebp-Ch] BYREF

  Scaleform::String::String(result);
  v3.Type = tStr;
  v3.SinkData.pStr = result;
  Scaleform::Format<unsigned long>(&v3, "{0}", v);
  return result;
}
