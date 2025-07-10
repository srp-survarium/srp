const char *__cdecl Scaleform::GFx::AS3::AsString(Scaleform::GFx::AS3::Abc::NamespaceKind kind)
{
  const char *result; // eax

  switch ( kind )
  {
    case NS_Public:
      result = "public";
      break;
    case NS_Protected:
      result = "protected";
      break;
    case NS_StaticProtected:
      result = "static protected";
      break;
    case NS_Private:
      result = "private";
      break;
    case NS_Explicit:
      result = "explicit";
      break;
    case NS_PackageInternal:
      result = "package internal";
      break;
    default:
      result = "Invalid Namespace type";
      break;
  }
  return result;
}
