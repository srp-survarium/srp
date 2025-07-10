void SpeedTree::CCore::SetError(char *format, ...)
{
  char string[256]; // [esp+4h] [ebp-108h] BYREF
  char *ap; // [esp+108h] [ebp-4h]
  va_list va; // [esp+118h] [ebp+Ch] BYREF

  va_start(va, format);
  va_copy(ap, va);
  _vsnprintf(string, 0xFFu, format, va);
  string[255] = 0;
  SpeedTree::CErrorHandler::SetError((SpeedTree::CErrorHandler *)&unk_A9C280, string);
}
