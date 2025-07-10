void __usercall vostok::resources::thread_local_data::~thread_local_data(
        vostok::resources::thread_local_data *this@<ecx>,
        int a2@<eax>)
{
  _DWORD *v3; // esi

  v3 = (_DWORD *)(a2 + 612);
  boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::unlink((boost::intrusive::rbtree_node<void *> *)(a2 + 612));
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 496));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 448));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 400));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 352));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 296));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 248));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 200));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 152));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 104));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 56));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 8));
}
