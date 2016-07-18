#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/python/suite/indexing/map_indexing_suite.hpp>
#include <cmath>
#include <vector>

double example_func(double a) {
  return std::sqrt(a);
}

std::vector<double> list_of_nums() {
  return std::vector<double>{1,2,3,4,5};
}


BOOST_PYTHON_MODULE(pycpp)
{
  using namespace boost::python;

  def("example", &example_func);
  def("list_of_nums", &list_of_nums);

  class_<std::vector<double> >("MyVector")
    .def(vector_indexing_suite<std::vector<double> >())
    ;
  
}
