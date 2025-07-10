DName *__cdecl UnDecorator::getTemplateName(DName *result, bool fReadTerminator)
{
  Replicator *v2; // ebx
  Replicator *v3; // esi
  Replicator *v4; // edi
  const char *v5; // eax
  bool v6; // zf
  DName *OperatorName; // eax
  DNameNode *node; // ecx
  const DName *TemplateArgumentList; // eax
  const DName *v10; // eax
  DName *v11; // eax
  Replicator localTemplateArgList; // [esp+0h] [ebp-A0h] BYREF
  Replicator localArgList; // [esp+2Ch] [ebp-74h] BYREF
  Replicator localZNameList; // [esp+58h] [ebp-48h] BYREF
  DName v15; // [esp+84h] [ebp-1Ch] BYREF
  DName v16; // [esp+8Ch] [ebp-14h] BYREF
  DName templateName; // [esp+94h] [ebp-Ch] BYREF
  bool fReadTemplateArguments; // [esp+9Fh] [ebp-1h] BYREF

  if ( *UnDecorator::gName == 63 && UnDecorator::gName[1] == 36 )
  {
    localArgList.index = -1;
    localZNameList.index = -1;
    localTemplateArgList.index = -1;
    v2 = UnDecorator::pTemplateArgList;
    v3 = UnDecorator::pArgList;
    UnDecorator::pArgList = &localArgList;
    v4 = UnDecorator::pZNameList;
    UnDecorator::pZNameList = &localZNameList;
    v5 = UnDecorator::gName + 2;
    UnDecorator::gName = v5;
    UnDecorator::pTemplateArgList = &localTemplateArgList;
    v6 = *v5 == 63;
    fReadTemplateArguments = 0;
    if ( v6 )
    {
      UnDecorator::gName = v5 + 1;
      OperatorName = UnDecorator::getOperatorName(&v16, 1, &fReadTemplateArguments);
    }
    else
    {
      OperatorName = UnDecorator::getZName(&v16, 1, 1);
    }
    node = OperatorName->node;
    *((_DWORD *)&templateName + 1) = *((_DWORD *)OperatorName + 1);
    templateName.node = node;
    if ( !node )
      UnDecorator::fExplicitTemplateParams = 1;
    if ( !fReadTemplateArguments )
    {
      TemplateArgumentList = UnDecorator::getTemplateArgumentList(&v16);
      v10 = operator+(&v15, 60, TemplateArgumentList);
      DName::operator+=(&templateName, v10);
      if ( templateName.node && templateName.node->getLastChar(templateName.node) == 62 )
        DName::operator+=(&templateName, 32);
      DName::operator+=(&templateName, 62);
      if ( fReadTerminator )
      {
        if ( *UnDecorator::gName )
          ++UnDecorator::gName;
      }
    }
    v11 = result;
    UnDecorator::pZNameList = v4;
    UnDecorator::pArgList = v3;
    UnDecorator::pTemplateArgList = v2;
    *result = templateName;
  }
  else
  {
    DName::DName(result, DN_invalid);
    return result;
  }
  return v11;
}
