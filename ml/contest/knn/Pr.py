import numpy as np
def build_precision_recall_curve(true_labels: np.ndarray, predicted_probas: np.ndarray) -> np.ndarray:
    """
    Данная функция строит PR-кривую для задачи бинарной классификации.
    В случае, когда нет ни одного объекта положительного класса функция должна вызывать ValueError().

    Args:
        true_labels (np.ndarray): Массив истинных меток класса.
            Состоит из 0 и 1. 1 считается меткой положительного класса.
        predicted_probas (np.ndarray): Массив предсказанных вероятностей
            принадлежности объекта к положительному классу.

    Returns:
        np.ndarray: Массив размерами (len(true_labels)+1, 2),
            где в каждой строчке стоит пара (recall, precision),
            первым элементом всегда идет (0, 1)
    """
    if(not np.any(true_labels)): raise ValueError()
    indexes_sorted=np.flip(np.argsort(predicted_probas))
    true_labels_sorted=np.take_along_axis(true_labels, indexes_sorted)
    predicted_probas_sorted=np.take_along_axis(predicted_probas, indexes_sorted)
    PR=np.zeros((len(true_labels)+1, 2))
    PR[0]=[0, 1]
    for i in range(len(true_labels)):
        tp, fp, fn = [0, 0, 0]
        for j in range(len(true_labels)):
            if(j<=i):
                if(true_labels_sorted[j]==1): tp+=1
                elif(true_labels_sorted[j]==0): fp+=1
            else: 
                if(true_labels_sorted[j]==1): fn+=1
        if(tp+fn!=0 and tp+fp!=0): PR[i+1]=[tp/(tp+fn), tp/(tp+fp)]
        # elif(tp+fn!=0): PR[i+1]=[tp/(tp+fn), 1]
        # elif(tp+fp!=0): PR[i+1]=[0, tp/(tp+fp)]
        else: PR[i+1]=[0, 1]

    return PR