void __userpurge boost::asio::detail::select_reactor::deregister_descriptor(
        boost::asio::detail::select_reactor *this@<ecx>,
        _RTL_CRITICAL_SECTION *a2@<edi>,
        stlp_std::priv::_List_node_base *descriptor,
        boost::asio::detail::select_reactor::per_descriptor_data *__formal,
        bool a5)
{
  boost::asio::detail::select_reactor *v5; // ecx
  stlp_std::priv::_List_node_base v6; // [esp+8h] [ebp-Ch] BYREF

  EnterCriticalSection(a2 + 1);
  v6._M_prev = (stlp_std::priv::_List_node_base *)boost::system::system_category();
  v6._M_next = (stlp_std::priv::_List_node_base *)995;
  boost::asio::detail::select_reactor::cancel_ops_unlocked(v5, (int)a2, descriptor, &v6);
  LeaveCriticalSection(a2 + 1);
}
