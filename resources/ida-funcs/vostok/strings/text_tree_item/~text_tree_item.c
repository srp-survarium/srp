void __usercall vostok::strings::text_tree_item::~text_tree_item(
        vostok::strings::text_tree_item *this@<ecx>,
        int a2@<eax>)
{
  vostok::strings::text_tree_item::clear((vostok::strings::text_tree_item *)a2);
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 64));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 16));
}
