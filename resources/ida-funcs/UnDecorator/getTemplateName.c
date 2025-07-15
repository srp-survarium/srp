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
  int v12; // [esp+0h] [ebp-A0h] BYREF
  int v13; // [esp+2Ch] [ebp-74h] BYREF
  int v14; // [esp+58h] [ebp-48h] BYREF
  DName v15; // [esp+84h] [ebp-1Ch] BYREF
  DName resulta; // [esp+8Ch] [ebp-14h] BYREF
  DName v17; // [esp+94h] [ebp-Ch] BYREF
  bool pfReadTemplateArguments; // [esp+9Fh] [ebp-1h] BYREF

  if ( *UnDecorator::gName == 63 && UnDecorator::gName[1] == 36 )
  {
    v13 = -1;
    v14 = -1;
    v12 = -1;
    v2 = UnDecorator::pTemplateArgList;
    v3 = UnDecorator::pArgList;
    UnDecorator::pArgList = (Replicator *)&v13;
    v4 = UnDecorator::pZNameList;
    UnDecorator::pZNameList = (Replicator *)&v14;
    v5 = UnDecorator::gName + 2;
    UnDecorator::gName = v5;
    UnDecorator::pTemplateArgList = (Replicator *)&v12;
    v6 = *v5 == 63;
    pfReadTemplateArguments = 0;
    if ( v6 )
    {
      UnDecorator::gName = v5 + 1;
      OperatorName = UnDecorator::getOperatorName(&resulta, 1, &pfReadTemplateArguments);
    }
    else
    {
      OperatorName = UnDecorator::getZName(&resulta, 1, 1);
    }
    node = OperatorName->node;
    *((_DWORD *)&v17 + 1) = *((_DWORD *)OperatorName + 1);
    v17.node = node;
    if ( !node )
      UnDecorator::fExplicitTemplateParams = 1;
    if ( !pfReadTemplateArguments )
    {
      TemplateArgumentList = UnDecorator::getTemplateArgumentList(&resulta);
      v10 = operator+(&v15, 60, TemplateArgumentList);
      DName::operator+=(&v17, v10);
      if ( v17.node && v17.node->getLastChar(v17.node) == 62 )
        DName::operator+=(&v17, 32);
      DName::operator+=(&v17, 62);
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
    *result = v17;
  }
  else
  {
    DName::DName(result, DN_invalid);
    return result;
  }
  return v11;
}
