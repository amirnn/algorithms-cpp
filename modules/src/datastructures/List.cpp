// Copyright 2025 by Amir Nourinia

module;
#include <functional>
module List;
import Sort;

namespace datastructures {
    template<std::totally_ordered T>
    void ASortableList<T>::sort(std::function<algorithms::ASort<T>()> const &algorithm) {
        algorithms::ASort<T> sortingAlgorithm = algorithm();
        sortingAlgorithm.sort(this);
    }

}



