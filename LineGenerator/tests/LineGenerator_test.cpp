#include <gtest/gtest.h>

#include <AllPossibleLinesGenerator.hpp>
#include <LineGeneratorFilter.hpp>
#include <FSTLineSequencer.hpp>
#include <LineFilterBuilder.hpp>
#include <ILineFilter.hpp>

#include <vector>
#include <tuple>
#include <algorithm>

/**
 * @brief Test fixture
 * Contains list of sequences, line length and corresponding possible lines
 * 
 */
class AllPossibleLinesGeneratorTest: public ::testing::Test
{
protected:
    // test case type
    using testCaseType = std::pair<unsigned int,
                            std::vector<NS::ILineGenerator::Line>>;
    void SetUp() override
    {

        auto vectorlexicographicSorter = [](const auto& v1, const auto& v2){
            return std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
        };

        // all possible lines from size 1 to 5
        testSequencesLines
            .push_back(
                testCaseType(
                    1,
                    {
                        {0},
                        {1}
                    }
                )
            );
        testSequencesLines
            .push_back(
                testCaseType(
                    2,
                    {
                        {0, 0},
                        {0, 1},
                        {1, 0},
                        {1, 1}
                    }
                )
            );
        testSequencesLines
            .push_back(
                testCaseType(
                    3,
                    {
                        {0, 0, 0},
                        {0, 0, 1},
                        {0, 1, 0},
                        {0, 1, 1},
                        {1, 0, 0},
                        {1, 0, 1},
                        {1, 1, 0},
                        {1, 1, 1}
                    }
                )
            );
        testSequencesLines
            .push_back(
                testCaseType(
                    4,
                    {
                        {0, 0, 0, 0},
                        {0, 0, 0, 1},
                        {0, 0, 1, 0},
                        {0, 0, 1, 1},
                        {0, 1, 0, 0},
                        {0, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 1, 1, 1},
                        {1, 0, 0, 0},
                        {1, 0, 0, 1},
                        {1, 0, 1, 0},
                        {1, 0, 1, 1},
                        {1, 1, 0, 0},
                        {1, 1, 0, 1},
                        {1, 1, 1, 0},
                        {1, 1, 1, 1}
                    }
                )
            );
        testSequencesLines
            .push_back(
                testCaseType(
                    5,
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1},
                        {0, 0, 0, 1, 0},
                        {0, 0, 0, 1, 1},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 1},
                        {0, 0, 1, 1, 0},
                        {0, 0, 1, 1, 1},
                        {0, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1},
                        {0, 1, 0, 1, 0},
                        {0, 1, 0, 1, 1},
                        {0, 1, 1, 0, 0},
                        {0, 1, 1, 0, 1},
                        {0, 1, 1, 1, 0},
                        {0, 1, 1, 1, 1},
                        {1, 0, 0, 0, 0},
                        {1, 0, 0, 0, 1},
                        {1, 0, 0, 1, 0},
                        {1, 0, 0, 1, 1},
                        {1, 0, 1, 0, 0},
                        {1, 0, 1, 0, 1},
                        {1, 0, 1, 1, 0},
                        {1, 0, 1, 1, 1},
                        {1, 1, 0, 0, 0},
                        {1, 1, 0, 0, 1},
                        {1, 1, 0, 1, 0},
                        {1, 1, 0, 1, 1},
                        {1, 1, 1, 0, 0},
                        {1, 1, 1, 0, 1},
                        {1, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1}
                    }
                )
            );

        for(auto& testSequenceLine : testSequencesLines){
            std::sort(testSequenceLine.second.begin(),
                        testSequenceLine.second.end(),
                        vectorlexicographicSorter);
        }
    }

    std::vector<testCaseType> testSequencesLines;
};

TEST_F(AllPossibleLinesGeneratorTest, HandlesSize0)
{
    EXPECT_EQ(NS::AllPossibleLinesGenerator(0).generateLines(), std::vector<NS::AllPossibleLinesGenerator::Line>());
}

TEST_F(AllPossibleLinesGeneratorTest, generateSize1to5) {
    auto vectorlexicographicSorter = [](const auto& v1, const auto& v2){
            return std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
        };

    for(const auto& testSequenceLine : testSequencesLines) {
        auto lines = NS::AllPossibleLinesGenerator(testSequenceLine.first).generateLines();

        std::sort(lines.begin(),
                    lines.end(),
                    vectorlexicographicSorter);

        EXPECT_EQ(lines, testSequenceLine.second);
    }
}