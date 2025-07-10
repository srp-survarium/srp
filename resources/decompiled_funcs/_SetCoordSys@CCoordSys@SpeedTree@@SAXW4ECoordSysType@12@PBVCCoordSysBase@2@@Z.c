void __cdecl SpeedTree::CCoordSys::SetCoordSys(
        enum SpeedTree::CCoordSys::ECoordSysType a1,
        const struct SpeedTree::CCoordSysBase *a2)
{
  SpeedTree::CCoordSys::m_eCoordSysType = a1;
  if ( a1 == COORD_SYS_CUSTOM )
    SpeedTree::CCoordSys::m_pCoordSys = a2;
  else
    SpeedTree::CCoordSys::m_pCoordSys = SpeedTree::CCoordSys::GetBuiltInConverter(a1);
}
