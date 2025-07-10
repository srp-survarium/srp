int __cdecl vostok::network_core::operator-<unsigned short>(
        const vostok::network_core::sequence_number<unsigned short> *left,
        vostok::network_core::sequence_number<unsigned short> *right)
{
  if ( vostok::network_core::sequence_number<unsigned short>::operator<=(right, left) )
    return ((int)&_sbh_sizeHeaderList + left->m_number - right->m_number) % 0x10000;
  else
    return -vostok::network_core::operator-<unsigned short>(right, left);
}
